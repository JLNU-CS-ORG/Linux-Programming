/*
 * file name: user.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 06:32:23 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	uid_t uid;
	gid_t gid;

	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	printf("User is %s\n", getlogin());
	printf("User id and group id number: uid=%d, gid=%d\n",
			uid, gid);
	pw = getpwuid(uid);
	printf("UID passwd entry:\nname=%s,"
			"uid=%d, gid=%d, home=%s, shell=%s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid,
			pw->pw_dir, pw->pw_shell);
	pw = getpwnam("root");
	printf("root passwd entry:\n");
	printf("name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir,
			pw->pw_shell);
	exit(0);
}
