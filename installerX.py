import requests
import os
import platform
import patoolib
#import getpass
import shutil
import distutils.dir_util
from clint.textui import progress


def get_essential():
    try:
        if not os.path.exists("dependencies.rar"):
            url = "{}".format(os.environ.get("specialLink"))
            r = requests.get(url, stream = True)
            path = "dependencies.rar"
            with open(path, 'wb') as f:
                total_length = int(r.headers.get('content-length'))
                for chunk in progress.bar(r.iter_content(chunk_size=1024), expected_size=(total_length/1024) + 1):
                    if chunk:
                        f.write(chunk)
                        f.flush()
        if os.path.exists("dependencies.rar"):
            print("Extracting Downloaded Files....")
            patoolib.extract_archive("dependencies.rar", outdir="{}".format(os.getcwd()))
            arduinoData = "ArduinoData"
            arduinoFolder = "Arduino"
            arduino15 = "Arduino15"
            #current_user = getpass.getuser()
            if os.path.exists("ArduinoData"):
                if platform.system() == "Windows" and platform.release() == "10":
                    print("Windows 10 Detected")
                    sourceData= f"{os.getcwd()}\\{arduinoData}"
                    sourceHardware= f"{os.getcwd()}\\{arduinoFolder}"
                    home = os.path.expanduser('~')
                    dest = os.path.join(home,'Documents')
                    dest_hidden = os.path.join(home,'AppData\\Local')
                    hidden_data = dest_hidden
                    x = dest
                    y = dest
                    x = x+f"\\{arduinoData}\\"
                    y = y+f"\\{arduinoFolder}\\"
                    hidden_data = hidden_data+f"\\{arduino15}\\"
                    if not os.path.exists(x):
                        os.mkdir(x)
                    print(x)
                    print("Copying Libraries.......")
                    distutils.dir_util.copy_tree(sourceData, x)

                    if not os.path.exists(y):
                        os.mkdir(y)
                    print(y)
                    print("Copying Hardware Files.....")
                    distutils.dir_util.copy_tree(sourceHardware, y)

                    if not os.path.exists(hidden_data):
                        os.mkdir(hidden_data)
                    print(hidden_data)
                    print("Copying Essential Files.....")
                    distutils.dir_util.copy_tree(sourceData, hidden_data)



    except Exception as e:
        print(e)


if __name__ == '__main__':
    get_essential()
