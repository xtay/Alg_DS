echo 'CC=gcc' > Makefile
echo 'CFLAGS=-O1 -I ../include' >> Makefile

echo '' >> Makefile
echo 'all: \' >> Makefile
for file in `ls *.c`
do
    obj=`echo ${file} | cut -d '.' -f 1 | sed -e 's/^/..\/build\//g' `
    echo "${obj}.o \\" >> Makefile
done

echo '' >> Makefile
echo '' >> Makefile

for file in `ls *.c`
do
    name=`echo ${file} | cut -d '.' -f 1`
    gcc -MM -I ../include ${file} | sed -e "s/^${name}.o/..\/build\/${name}.o/g" >> Makefile
    echo -e "\t\$(CC) \$(CFLAGS) -c \$< -o \$@" >> Makefile
    echo "" >> Makefile
done
