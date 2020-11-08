PROJECTDIR='../libasm'

make -C $PROJECTDIR re
ln -s $PROJECTDIR/libasm.a .

clang -g main.c test/*.c  -I ./includes -L . -lasm
./a.out

rm libasm.a