#!bin/sh

# Create a user
adduser -D -h /var/ftp $FTP_USER && \
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd && \ 
echo "User $FTP_USER has been created" && \
mkdir -p /var/ftp && \ 
chown -R $FTP_USER:$FTP_USER /var/ftp && \
chmod 755 /var/ftp

# Start the FTP server
echo "Starting vsftpd server..."
vsftpd /etc/vsftpd/vsftpd.conf
