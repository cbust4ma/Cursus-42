FROM debian:buster
MAINTAINER cbustama@student.42urduliz.com
COPY ./conf/* /tmp
RUN apt update && apt -y install curl vim\
	&& apt install -y mariadb-server && chmod +x /tmp/sql.sh\
	&& mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld\
	&& /bin/bash -c /tmp/sql.sh && apt clean && rm -rf /var/lib/apt/lists/*
CMD ["sh","-c", "./tmp/create.sh > /tmp/create.sql && mysqld --init-file=/tmp/create.sql && rm -rf create.sql create.sh"]
EXPOSE 3306

