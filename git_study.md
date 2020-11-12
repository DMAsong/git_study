# git指令集

## 1安装git

```c
$ git
The program 'git' is currently not installed. You can install it by typing:
sudo apt-get install git
```

该提示没有安装git,百度git官网下载,一路next安装即可

## 2 输入git用户信息

```c
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
```



## 3 初始化git仓库

```c
$ git init
```

添加文件到git仓库

```c
git add "文件名[英]"
```

多文件添加,调用多次

提交文件

```c
git commit -m "注释"
```

## 4 查看工作区状态

```c
git status
```

对比版本文件差异

```c
git diff file_name
```

file_name --- 文件名带后缀

>例如,对比文件readme.txt
>
>git diff readme.txt

## 5 查看日志

```c
git log
```

如果嫌输出的信息太多可以输入

```c
$ git log --pretty=oneline
```

如果想查看以前删除的日志

```c
git reflog
```

reflog 记录了每一次命令

## 6回退版本

```c
git reset --hard HEAD^
```

HEAD表示当前版本

HEAD^表示上一个版本

HEAD^^上上个版本,以此类推上n个版本

也可以不用HEAD,比如用版本号(在日志查看)

```c
git reset --hard 版本号前几个号即可
```

>```c
>$ git reset --hard 1094a
>    HEAD is now at 83b0afe append GPL
>```

## 7 丢弃工作区内容

在你要add的时候,发现内容有需要修改错误的地方可以丢弃掉工作区的内容

```c
git checkout -- file_name
```

修改的内容就被还原提交之前的了

如果你已经add了,在commit之前发现有错误

先把暂存区的修改撤销掉 

```c
$ git reset HEAD file_name
```

然后在丢弃工作区的修改内容

```
$ git checkout -- file_name
```

## 8 删除文件

```C
git rm file_name
```

然后

```C
git commit -m "xxx删除文件"
```

误删除可以check/reset

## 9 生成ssh秘钥

```c
$ ssh-keygen -t rsa -C "youremail@example.com"
```

 `id_rsa`是私钥，不能泄露出去，`id_rsa.pub`是公钥 ,可以放心地告诉任何人。

将公钥输入到github上即可 

## 10 将本地仓提交到新建的远程仓库

```c
$ git remote add origin git@github.com:michaelliao/learngit.git
```

请千万注意，把上面的`michaelliao`替换成你自己的GitHub账户名，否则，你在本地关联的就是我的远程库，关联没有问题，但是你以后推送是推不上去的，因为你的SSH Key公钥不在我的账户列表中。

添加后，远程库的名字就是`origin`，这是Git默认的叫法，也可以改成别的，但是`origin`这个名字一看就知道是远程库。

将本地内容推送到远程仓库

```c
$ git push -u origin master
```

添加成功之后,在修改就可以用push提交

```c
git push
```

## 11 克隆远程仓库

```c
$ git clone git@github.com:michaelliao/gitskills.git
```

如果有多个人协作开发，那么每个人各自从远程克隆一份就可以了。

你也许还注意到，GitHub给出的地址不止一个，还可以用`https://github.com/michaelliao/gitskills.git`这样的地址。实际上，Git支持多种协议，默认的`git://`使用ssh，但也可以使用`https`等其他协议。

使用`https`除了速度慢以外，还有个最大的麻烦是每次推送都必须输入口令，但是在某些只开放http端口的公司内部就无法使用`ssh`协议而只能用`https`

## 12 创建分支

```c
$ git checkout -b dev (创建并切换分支dev)
等同于:{
   		 $ git branch dev (创建分支)
         $ git checkout dev (切换分支)
		}
```

查看当前的分支

```c
git branch
```

Git鼓励大量使用分支：

查看分支：`git branch`

创建分支：`git branch `

切换分支：`git checkout `或者`git switch `

创建+切换分支：`git checkout -b `或者`git switch -c `

合并某分支到当前分支：`git merge `+分支名 

删除分支：`git branch -d+分支名  `

 `git log --graph`命令可以看到分支合并图 

# 13 查看分支合并图

```c
$ git log --graph --pretty=oneline --abbrev-commit
```

# 14 普通模式合并分支

```c
$ git merge --no-ff -m "注释merge with no-ff" 分支名
```

# 15 存储工作区

```c
git stash
```

# 16 恢复工作现场

```c
git stash pop
```

# 17 查看存储内容

```c
git stash list
```

# 18 复制特定的分支

```c
git cherry-pick <commit>
```

