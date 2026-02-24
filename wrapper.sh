cdx() {
    # Capture everything
    raw_output=$(/mnt/c/Users/werener/Desktop/gitfolder/cdx/release/cdx "$@" 2>&1)
    # Extract path (if exists) but don't show it
    path=$(echo "$raw_output" | sed -n 's/.*\[CDX_PATH\]\(.*\)\[\/CDX_PATH\].*/\1/p')

    # Show everything EXCEPT the path and its delimiters
    clean_output=$(echo "$raw_output" | sed 's/\[CDX_PATH\].*\[\/CDX_PATH\]//g')
    echo -e "$clean_output"
    echo -e $path
    # Use the path silently
    if [ -n "$path" ] && [ -d "$path" ]; then
        cd $path
    fi
}