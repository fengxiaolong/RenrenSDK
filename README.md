A SDK of renren.com written in pure c
===

MAC OS X
-------

* install homebrew

  ```ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"```
  关于homebrew的介绍可以看它的[官网](mxcl.github.io/homebrew/),它的主要功能就是让你像在Linux下一样
  通过命令行的方式来安装和卸载软件,如果出现编译的时候说找不到库的话,你
  需要把你安装的库,例如glib的目录添加到PATH变量中,添加的方法跟在Linux
  下面是一样的.

* install sqlite3

  ```brew install sqlite3```
  
* install json-glib

  ```brew install json-glib```

  上面的语句会帮你把json-glib所依赖的所有库都自动安装好
  
Ubuntu/Debian
---------

* install sqlite3

  ```apt-get install sqlite3```

* install json-glib

  ```apt-get install build-essential libjson0 libjson0-dev libjson0-dbg
  libjson-glib-1.0-0 libjson-glib-1.0-0-dev libjson-glib-1.0-0-dbg
  libjson-glib-1.0-0-doc ```

  如果你想看glib的文档,你可以通过浏览器浏览这个[网址](file:///usr/share/gtk-doc/html/json-glib/index.html)

项目结构说明
------------

*include* 存放头文件,包括第三方库

*src* 存放源码

*test* 存放测试用例

*document* 存放文档

*nbproject* 这个文档是用netbeans IDE打开时候所产生的附加文档

调用SDK需要注意的事项
-----------

  SDK中，所有的文件名称和这个文件中所代表的函数名称是一样的，所以你知道了这个文件的名
字，你就知道了这个文件中所包含的函数的名字，然后根据文档，传入所需要的
参数，你就可以获得服务器返回的值，这些值可能存在数据库里面，可能存在一
个结构体中，可能存在json文件中，在一些文件中，用了cjson来解析了服务器
返回的json文件，这样更方便调用函数的人获得所需要的数据，当然，为了存储
的便利，有一些数据可能会存储在数据库中，函数需要的参数，以及函数返回的
数据的类型，还有返回数据的存储方式在下面的文档中都有详细的介绍，方便调
用者。

* AccessToken.h

  定义了程序中用到的宏
  
* GetAccessToken.h

  像人人网发送请求，获取授权页面，保存为`result.html`在浏览器打开这个文件后，输入你的校内网用户名和密码，在跳转后的页面中的url中，你可以提取你的access_token，access_token就是在跳转后的url中的access_token=后面，在&expires_in前面的那一串数字，在我们后面的功能中，需要你提供这个access_token，这样我们的应用才可以读取你的一些信息，以便更好的为你服务，读取你的好友列表，你的最近来访等等，帮你做更进一步的分析。
  
* GetUserInfo.h

  这个接口的主要功能是获取用户信息，你唯一需要做的就是传给GetUserInfo
  函数一个access_token的参数，当我们像服务器做出请求后，服务器返回给我
  们的是一个json格式的文件，我们用c把这个json的文件解析，然后存储在我
  们定义的UserInfo的数据结构中，当你需要任何数据的时候，创建一个
  UserInfo类型的变量，然后调用GetUserInfo函数，你就得到了你所需要的一
  切

* GetCurrentSessionID.h

  这个接口的功能是通过传递一个access_token到函数中，然后服务器会返回一
  个当前会话的用户ID。