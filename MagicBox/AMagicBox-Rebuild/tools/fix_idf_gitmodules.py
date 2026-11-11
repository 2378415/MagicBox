"""Remove pruned components from ESP-IDF's .gitmodules so the submodule check passes.

We pruned six components whose submodules could not be fetched in this network
(mqtt, protobuf-c, unity, spiffs, mbedtls, openthread).  None of them is used by
the MAKCU rebuild apps, but `tools/cmake/git_submodules.cmake` refuses to
configure while they are listed but uninitialised.

Usage: python fix_gitmodules.py [idf_root]
"""
import os
import re
import sys

DROP = (
    'components/mqtt/esp-mqtt',
    'components/protobuf-c/protobuf-c',
    'components/unity/unity',
    'components/spiffs/spiffs',
    'components/mbedtls/mbedtls',
    'components/openthread/openthread',
)


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else r'D:\esp-idf'
    path = os.path.join(root, '.gitmodules')
    text = open(path, encoding='utf-8').read()
    blocks = re.split(r'(?=\[submodule )', text)
    kept = []
    for block in blocks:
        m = re.search(r'path\s*=\s*(\S+)', block)
        if m and m.group(1) in DROP:
            print('drop', m.group(1))
            continue
        kept.append(block)
    open(path, 'w', encoding='utf-8').write(''.join(kept))
    print('entries left:', sum(1 for b in kept if '[submodule' in b))


if __name__ == '__main__':
    main()
