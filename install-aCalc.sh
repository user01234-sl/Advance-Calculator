echo " Installing... "
pkg install clang -y
mkdir -p ~/.aCalc
clang ./aCalc.c -o ~/.aCalc/aCalc -lm
chmod +x ~/.aCalc/aCalc
echo "alias acalc='~/.aCalc/aCalc' " >> .bashrc
echo " Done "
echo " Usage:acalc [operation] [num1] [num2](optional)"
