#!/usr/bin/env bash
set -euo pipefail

usage() {
    echo "Usage: $0 <section> <problem_name>"
    echo "  e.g. $0 introductory_problems my_problem"
    exit 1
}

[[ $# -ne 2 ]] && usage

SECTION="$1"
PROBLEM="$2"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TARGET="$SCRIPT_DIR/$SECTION/$PROBLEM"

if [[ -d "$TARGET" ]]; then
    echo "Error: '$TARGET' already exists." >&2
    exit 1
fi

mkdir -p "$TARGET"

cat > "$TARGET/$PROBLEM.cpp" << 'EOF'
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
EOF

echo "Created: $TARGET/$PROBLEM.cpp"
