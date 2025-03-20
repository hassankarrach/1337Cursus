#!/bin/sh

echo "FTP Server Setuping ..."

# Create a new user
useradd -m $FTP_USER
echo "${FTP_USER}:${FTP_PASS}" | chpasswd

# permissions
usermod -aG www-data $FTP_USER

mkdir -p /var/run/vsftpd/empty
echo local_root=/var/www/wordpress >> /etc/vsftpd.conf
echo write_enable=YES >> /etc/vsftpd.conf
echo chown_uploads=YES >> /etc/vsftpd.conf # change the owner of the uploaded files
echo chown_username=www-data >> /etc/vsftpd.conf

exec vsftpd