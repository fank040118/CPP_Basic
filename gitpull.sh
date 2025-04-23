#!/bin/bash

# 切换到正确的目录
cd /home/fank0/CPP_Basic

# 检查是否使用HTTPS
REMOTE_URL=$(git remote get-url origin)
if [[ $REMOTE_URL == https://* ]]; then
    echo "检测到HTTPS URL，正在转换为SSH URL..."
    SSH_URL="git@github.com:$(echo $REMOTE_URL | sed 's|https://github.com/||')"
    git remote set-url origin "$SSH_URL"
    echo "已将远程URL更改为: $SSH_URL"
fi

# 显示当前状态
echo "当前本地状态:"
git status -s

# 拉取远程更新
echo "正在从GitHub拉取更新..."
git pull origin main

if [ $? -eq 0 ]; then
    echo "更新成功完成!"
else
    echo "更新过程中发生错误，可能存在冲突。"
    echo "请手动解决冲突后，使用 git add 标记已解决，然后 git commit 完成合并。"
fi