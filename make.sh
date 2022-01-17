#!/bin/bash
gcc -o zshooter src/main.c
echo -e "#!/bin/bash\nx-terminal-emulator -e ./zshooter" > run.sh
chmod u+x run.sh zshooter
