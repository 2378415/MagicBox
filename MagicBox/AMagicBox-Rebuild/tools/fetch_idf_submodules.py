#!/usr/bin/env python3
"""Populate IDF submodules from codeload tarballs (git:// is blocked on this network).

`git submodule update` times out for github.com:443, but codeload.github.com
serves the same commit as a tarball.  This script reads the pinned gitlink
commits from the IDF index, downloads each tarball and extracts it into the
submodule directory.

Usage: python tools/fetch_idf_submodules.py [idf_root]
"""
import os
import subprocess
import sys
import tarfile
import urllib.request

SUBMODULES = [
    ('components/mbedtls/mbedtls', 'espressif/mbedtls'),
    ('components/mqtt/esp-mqtt', 'espressif/esp-mqtt'),
    ('components/protobuf-c/protobuf-c', 'protobuf-c/protobuf-c'),
    ('components/unity/unity', 'ThrowTheSwitch/Unity'),
    ('components/spiffs/spiffs', 'pellepl/spiffs'),
    ('components/openthread/openthread', 'espressif/openthread'),
]


def gitlink(root, path):
    out = subprocess.run(['git', 'ls-tree', 'HEAD', path], cwd=root,
                         capture_output=True, text=True).stdout.strip()
    if not out:
        raise SystemExit(f'{path} is not a gitlink in {root}')
    return out.split()[2]


def fetch(root, path, repo):
    target = os.path.join(root, path)
    if os.path.isdir(target) and len(os.listdir(target)) > 3:
        print(f'{path}: already populated')
        return True
    sha = gitlink(root, path)
    url = f'https://codeload.github.com/{repo}/tar.gz/{sha}'
    tmp = os.path.join(root, '.submodule_dl', sha + '.tar.gz')
    os.makedirs(os.path.dirname(tmp), exist_ok=True)
    print(f'{path}: {sha[:12]} <- {url}')
    try:
        urllib.request.urlretrieve(url, tmp)
    except Exception as exc:
        print(f'  FAILED download: {exc}')
        return False
    os.makedirs(target, exist_ok=True)
    with tarfile.open(tmp) as tf:
        root_prefix = tf.getmembers()[0].name.split('/')[0]
        for member in tf.getmembers():
            if not member.name.startswith(root_prefix):
                continue
            rel = member.name[len(root_prefix):].lstrip('/')
            if not rel:
                continue
            member.name = rel
            tf.extract(member, target, filter='data')
    print(f'  extracted {len(os.listdir(target))} entries')
    return True


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else r'D:\esp-idf'
    ok = 0
    for path, repo in SUBMODULES:
        if fetch(root, path, repo):
            ok += 1
    print(f'{ok}/{len(SUBMODULES)} submodules populated')
    return 0 if ok == len(SUBMODULES) else 1


if __name__ == '__main__':
    sys.exit(main())
