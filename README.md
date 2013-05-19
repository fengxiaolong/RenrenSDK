A SDK of renren.com written in pure c
===

* AccessToken.h

  定义了程序中用到的宏
  
* GetAccessToken.h

  像人人网发送请求，获取授权页面，保存为`result.html`在浏览器打开这个文件后，输入你的校内网用户名和密码，在跳转后的页面中的url中，你可以提取你的access_token，access_token就是在跳转后的url中的access_token=后面，在&expires_in前面的那一串数字，在我们后面的功能中，需要你提供这个access_token，这样我们的应用才可以读取你的一些信息，以便更好的为你服务，读取你的好友列表，你的最近来访等等，帮你做更进一步的分析。
  
* GetUserInfo.h

  这个接口的主要功能是获取用户信息，你唯一需要做的就是传给GetUserInfo函数一个access_token的参数，当我们像服务器做出请求后，服务器返回给我们的是一个json格式的文件，我们用c把这个json的文件解析，然后存储在我们定义的UserInfo的数据结构中，当你需要任何数据的时候，创建一个UserInfo类型的变量，然后调用GetUserInfo函数，你就得到了你所需要的一切