# WORKDIR /app
	==> specify where future commands will run and the directory files will be copied inside the container image.

# CMD VS ENTRYPOINT
	# CMD: specifies the Default command to run when the container starts.
	# CMD: Can be overridden by providing a command in docker run (e.g., docker run mariadb bash runs bash instead).

	# ENTRYPOINT: Defines the executable to run when the container starts, treating CMD as arguments to the executable.
	# ENTRYPOINT: Cannot be overridden by providing a command in docker run. unless you use the --entrypoint flag.

	==> How it works :
	    # when container starts, Docker combines the ENTRYPOINT and CMD together to run the final command.
				# if only CMD is specified, it will be used as the final command.
				# if both are specified, CMD will be used as arguments to ENTRYPOINT. (ex : ENTRYPOINT ["echo", "Hello"] CMD ["world"] => echo Hello world)
				# if neither is specified, the container will exit immediately || fails to start.


	==> MariaDb example :
		# CMD ["/usr/local/bin/init.sh"] will :
			# Runs init.sh script as the main process (PID 1) of the container.
			# inside init.sh, exec mysqld_sade replaces the shell with mariadb daemon, keeping it in the foreground (crucial for Docker).
		# if i used ENTRYPOINT ["/usr/local/bin/init.sh"] Same effect as CMD, unless i will add CMD with arguments (ex, CMD ["--verbose"]).

	==> Final note :
		# CMD : easilly overriden (ex : docker run mariadb bash)
		# ENTRYPOINT : Forces init.sh to run, makes it harder to override (usefull for ensuring initialization).

		