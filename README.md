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

- If you are using a Linux distribution, I think you know how to install docker. But anyway, here is an example installation instruction for Ubuntu: [https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)

### 2. Pull the youBot-ready Docker image

For each OS just run in terminal:

```bash
docker pull tonykolomeytsev/youbot:devcontainer
```

> Btw on Windows 10/11 it is better to use PowerShell to run docker commands

### 3. Run Docker container and mount volumes

Most likely, you would like your projects to be stored locally on your computer and not disappear when docker is shut down. Therefore, you need to create a folder for youBot projects in a convenient place, for example:
- For Windows: `%USERPROFILE%\YouBotProjects`
- For Mac OS and Linux: `~/YouBotProjects`

And then:
- For Windows and Mac OS users:
    
    Run Docker Desktop and find the `tonykolomeytsev/youbot` image, press `Run` button.
    <details>
    <summary>Screenshot</summary>

    ![Docker Desktop Images Tab](https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot1.png)

    </details>

    In the dialog that appears, specify the `Container name`. In the `Volumes` section, in the `Host path` field, specify the path to the folder where projects for youbot will be stored. In the `Container path` field write `/root/workspace`.

    <details>
    <summary>Screenshot</summary>

    ![Docker Desktop Images Tab](https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot2.png)
    
    </details>

    To make sure your container is running, go to the Containers tab.

    <details>
    <summary>Screenshot</summary>

    ![Docker Desktop Images Tab](https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot3.png)
    
    </details>

- For Linux users:

    Start the docker container:
    ```
    docker run --name youbot -itd -v <youbot_projects_path>:/root/workspace tonykolomeytsev/youbot:devcontainer
    ```

    WIth option `--name` specify the container name. With option `-v` specify the path to the folder where projects for youbot will be stored and `/root/workspace` for container path. 
    
    Options `-i`, `-t`, is for... you wil read in `docker run --help`. Option `-d` to not go inside the container.

    To make sure your container is running, run in terminal:

    ```bash
    docker ps
    ```

### 4. Create your first project

Great, after all these manipulations, we have a working container with Ubuntu and installed dependencies for youBot inside.

To create a new project for youBot, which consists of template `CMakeLists.txt` and `src/main.cpp`, you need to go inside the container:

```bash
docker exec -it bash youbot
```

Inside the container, run the command `youbot_new_project <project_name>` to create a new project.

```bash
youbot_new_project laba_omr_3
```

Congratulations, your project is located inside the `/root/workspace/omr_laba_3/` folder. All project files will also be in your `~/YouBotProjects` folder.

> For details run 
> ```bash
> cat /usr/local/bin/youbot_new_project
> ```

### 5. Open project in Visual Studio Code

Install [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) plugin in VSCode.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot4.png">
</p>

Then click on the green button at the bottom left in the VSCode.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot5.png">
</p>

Select `Attach to running container...` option.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot6.png">
</p>

And select the container you started earlier.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot7.png">
</p>

Wait for VSCode to load, then click `File` -> `Open Folder...` Select the folder with your project.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot8.png">
</p>

Specify the SDK for the project.

<p align="center">
    <img src="https://github.com/tonykolomeytsev/youbot_devcontainer/raw/master/media/screenshot9.png">
</p>

### 6. Build the project and run

> TODO

