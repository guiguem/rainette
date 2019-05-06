# Rainette

## Installation instructions

- mkdir build
- cd build
- cmake ..
- make -j3
- make install

## Using Docker

### Pull a Docker image

Images representing the master branch installation are available on the IN2P3 Gitlab and you can pull them from there.
This method is recommanded when you just want to run the software and you don't need to edit the source code.
First login to Gitlab:

```bash
docker login gitlab-registry.in2p3.fr
```

Then pull the version you wish to use, e.g.:

```bash
docker pull gitlab-registry.in2p3.fr/t2k/rainette:develop
```

(note the change of the version tag at the end of the command).

Finally, run the image:

```bash
docker run --rm -it gitlab-registry.in2p3.fr/t2k/rainette:develop
```

You can also mount a folder inside the container (to access host computer data for example):

```bash
docker run -v <local-folder>:/host--rm -it gitlab-registry.in2p3.fr/t2k/rainette:develop
```

Final step: source the environment in the container:

```bash
source /usr/local/t2k/rainette/v0.0.1/setup.sh
```

### Create the image locally

You can build a Docker image by using your local cloned repository of Rainette.
This kind of build is for people wanting to just build and run the code as is in the current repository.
This method is not very convenient when developping new code and testing it in the docker environment: use the next method instead.

First login to Gitlab:

```bash
docker login gitlab-registry.in2p3.fr
```

Inside the Rainette folder, make sure your have all the submodules:

```bash
git submodule update --init --recursive
````

and then run:

```bash
docker build -t rainette .
```

This will install the software inside the container and produce a `rainette` image.
You can then access the software by running:

```bash
docker run --rm -it rainette
source /usr/local/t2k/rainette/v0.0.1/setup.sh
```

### Create the image locally for software developpment purposes

You can build a Docker image by using your local cloned repository of Rainette.
Contrary to the previous method, this method described below is intended for software developpers that need/want to be able to edit the code and rebuild it quickly.
The docker container used in this method will serve more as a testbench than a production version.

First login to Gitlab:

```bash
docker login gitlab-registry.in2p3.fr
```

Inside the Rainette folder, make sure your have all the submodules:

```bash
git submodule update --init --recursive
````

and then run:

```bash
docker pull gitlab-registry.in2p3.fr/t2k/applecrate:v0.0.2
```

and

```bash
docker run -v $(pwd):/rainette -it gitlab-registry.in2p3.fr/t2k/applecrate:v0.0.2
```

This last command will spin a docker container up using the applecrate base image and mound the current folder into the container: here we are mounting the rainette source code.
From there, all you need to do is to source the base dependencies (such as root) and then build the code commands as described above.
This should look like

```bash
source /usr/local/t2k/common/v0.0.2/setup.sh
cd /rainette
mkdir build
cmake ..
make -j3 install
```

You can then edit the code from inside or outside the container and rebuild using

```bash
make -j3 install
```

without exiting the container.