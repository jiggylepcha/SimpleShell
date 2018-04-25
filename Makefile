all: ls rm mkdir cat shell date

shell: shell.c
	gcc shell.c -o shell

ls: ls.c
	gcc ls.c -o ls

mkdir: mkdir.c
	gcc mkdir.c -o mkdir

cat: cat.c
	gcc cat.c -o cat

date: date.c
	gcc date.c -o date

clean:
	rm shell ls cat mkdir date rm