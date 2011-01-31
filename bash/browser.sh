URL="http://www.cs.mcgill.ca/~pmoore6/welcome.html"
[[ -x $BROWSER ]] && exec "$BROWSER" "$URL"
path=$(which xdg-open || which gnome-open) && exec "$path" "$URL"
echo "Can't find browser..."
