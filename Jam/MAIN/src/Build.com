! Bootstrap build script for Jam
! On OPENVMS you need the next line
! $ cc := cc/stand=vaxc
$ cc compile.c
$ cc expand.c
$ cc execvms.c
$ cc filevms.c
$ cc hash.c
$ cc headers.c
$ cc lists.c
$ cc make.c
$ cc newstr.c
$ cc option.c
$ cc parse.c
$ cc regexp.c
$ cc rules.c
$ cc scan.c
$ cc search.c
$ cc timestamp.c
$ cc variable.c
$ cc jam.c
$ cc jamgram.c
$ link/exe=jam.exe compile.obj, execvms.obj, expand.obj, filevms.obj, -
    hash.obj, headers.obj, lists.obj, make.obj, newstr.obj, option.obj, -
    parse.obj, regexp.obj, rules.obj, scan.obj, search.obj, timestamp.obj, -
    variable.obj, jam.obj, jamgram.obj
