# youBot devcontainer

A simple Docker container for building projects for KUKA youBot. 

The Docker image `tonykolomeytsev/youbot:devcontainer` already has all the necessary dependencies for building projects for KUKA youBot, including the `YouBotDriver` library.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/robot.png">
</p>

The image based on Ubuntu-20.04 and uses my own a bit modified [fork](https://github.com/tonykolomeytsev/youbot_driver) of the [youbot/youbot_driver](https://github.com/youbot/youbot_driver) sources. This image has no ROS support, but it is easy to implement.

## What the heck is that?

You can now write scripts for the robot on any computer, with any OS.

## The simplest way to use

### 1. Install Docker

- If you are using Windows 10/11 or Mac OS, install Docker Desktop:
    [https://www.docker.com/get-started/](https://www.docker.com/get-started/)

- If you are using a Linux distribution, I think you know how to install dockerю But anyway, here is an example installation instruction for Ubuntu: [https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)

### 2. Pull the youBot-ready Docker image

For each OS just run in terminal:

```bash
docker pull tonykolomeytsev/youbot:devcontainer
```

> Btw on Windows 10/11 it is better to use PowerShell to run docker commands

### 3. Run Docker container and mount volumes

> TODO

### 4. Create your first project

> TODO

### 5. Build the project and run

> TODO

