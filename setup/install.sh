cp -a ./language_tool /usr/local/UBTTools/
if [ ! -d "/home/oneai/.config/language_tool" ]; then
  mkdir /home/oneai/.config/language_tool
fi
cp -a ./language_tool_en_US.qm /home/oneai/.config/language_tool/
echo "安装成功后需要手动修改sudoer给程序赋root免密权限
sudo vim /etc/sudoers
在最下方oneai ALL=NOPASSWD:后添加 ,/usr/local/UBTTools/language_tool"
