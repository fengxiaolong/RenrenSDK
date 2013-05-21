install json-glib on mac
========

* brew install json-glib

brew是一个让你在mac上安装一些第三方库的工具，例如Linux的一些库，这样你可以通过命令行来安装很多有用的东西

brew会把json-glib所依赖的所有东西自动安装好

* 编译时选项

gcc main.c `pkg-config --cflags --libs`
