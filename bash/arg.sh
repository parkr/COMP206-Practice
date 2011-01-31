#! /bin/bash
#echo Your command is ${0}
#echo Your first argument is ${1}
#echo Your second argument is ${2}
#echo your third argument is ${3}
#!/bin/bash
echo "OPTIND starts at $OPTIND"
while getopts ":sf:d:" optname
  do
    case "$optname" in
	  "s")
	    echo "Option $optname activated."
	    ;;
      "f")
        echo "Option $optname has value $OPTARG"
		
        ;;
      "d")
        echo "Option $optname has value $OPTARG"
        ;;
      "?")
        echo "Unknown option $OPTARG"
        ;;
      ":")
        echo "No argument value for option $OPTARG"
        ;;
      *)
      # Should not occur
        echo "Unknown error while processing options"
        ;;
    esac
    echo "OPTIND is now $OPTIND"
  done