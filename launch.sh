PROJECTDIR='../libasm'

make -C $PROJECTDIR
ln -s $PROJECTDIR/libasm.a .

clang main.c test/t_strlen.c  -I ./includes -L . -lasm
./a.out

rm libasm.a