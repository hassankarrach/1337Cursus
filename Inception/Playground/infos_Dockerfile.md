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


   # CMD VS ENTRYPOINT (THE COMPHREHENSIVE) 

Feature			CMD																								ENTRYPOINT
Purpose			Provides a default command but can be overridden at runtime	Defines the main executable, 		cannot be easily overridden
Overridable?	Yes, by passing a command in docker run															No (unless --entrypoint is explicitly used)
Syntax			CMD ["executable", "arg1", "arg2"] (preferred JSON array format)								ENTRYPOINT ["executable", "arg1", "arg2"] (preferred JSON format)
Example			CMD ["nginx", "-g", "daemon off;"]																ENTRYPOINT ["nginx", "-g", "daemon off;"]
Use Case		Good for providing default behavior (e.g., running a script or process by default)				Best for forcing a mandatory command (e.g., when building a CLI tool)
		