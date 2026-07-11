echo " Installing... "
pkg install clang -y
clang ./aCalc.c -o ~/.aCalc/aCalc -lm
chmod +x ~/.aCalc/aCalc
echo "alias acalc='~/.aCalc/aCalc' " >> .bashrc
echo " Done "
