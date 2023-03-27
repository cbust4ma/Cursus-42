FROM debian:buster
MAINTAINER cbustama@student.42urduliz.com
COPY ./conf/setup.sh /tmp
RUN apt-get update && apt -y install curl wget netcat tar\
        && apt -y install vim\
	&& curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar\
	&& chmod +x wp-cli.phar && mv -f wp-cli.phar /usr/local/bin/wp\
        && apt -y install php php-fpm  php-mysql php-gd php-xml php-curl\
        && apt clean && rm -rf /var/lib/apt/lists/*\ && service php7.3-fpm restart\ 
	&& chmod +x /tmp/setup.sh  && apt -y remove  $(dpkg -l | grep -w apache2 | awk '{print $2}')
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
RUN sed -i 's/^pid = \/run\/php\/php7\.3-fpm\.pid$/pid = \/var\/run\/php-fpm7.3.pid/' /etc/php/7.3/fpm/php-fpm.conf
#CMD ["sh", "-c", "/usr/sbin/php-fpm7.3 -F && ./tmp/setup.sh"]
CMD ["sh", "-c", "./tmp/setup.sh && /usr/sbin/php-fpm7.3 -F"]

EXPOSE 9000
