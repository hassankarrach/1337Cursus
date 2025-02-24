# docker build -t my-username/my-image .
	==> Builds an image (WITH TAG)
	==> -t : Tagging images is the method to provide an image with a memorable name :
		==> [HOST[:PORT_NUMBER]/]PATH[:TAG]
		==> if image already exist : docker image tag my-username/my-image another-username/another-image:v1
	==> used for re-build too.

# docker run --name=[container_name] -ti [image_name]:version
# docker exec -it [container_name] EXECUTABLE
	==> -d : detached mode (run the container in the background, will not block the container)
	==> will build a container from the image
	==> -t : stands for (TTY - Terminal Emulation) Needed for interactive shells like bash or sh.
	==> -i : stands for InteractiveMode (Keeps STDIN open)
	==> -p : port mapping (host_port:container_port)
	==> --env-file my-env-file.env : to pass environment variables
	==> --env : to pass environment variables (one by one)
	==> --rm : remove the container after it stops
	==> --network : to specify the network
	==> --network-alias : to specify the network alias

	
		
# docker image history [image_name]
	==> will list the layers of an image

# docker start [container_name]
	==> will start a container
	==> re-start a stopped container
		docker start -it


# docker port [[container_name]]
	==> Checks the port mapped with the container port