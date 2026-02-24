cdx() {
    raw_output=$(/home/werener/Desktop/gitfolder/cdx/release/cdx "$@" 2>&1)
    path=$(echo "$raw_output" | sed -n 's/.*\[CDX_PATH\]\(.*\)\[\/CDX_PATH\].*/\1/p')

    clean_output=$(echo "$raw_output" | sed 's/\[CDX_PATH\].*\[\/CDX_PATH\]//g')
    echo -e "$clean_output"
    echo -e $path
    # Use the path silently
    if [ -n "$path" ] && [ -d "$path" ]; then
        cd $path
    fi
}