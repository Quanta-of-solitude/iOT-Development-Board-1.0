import requests
import os
import platform
import patoolib
#import getpass
import shutil
import distutils.dir_util
from clint.textui import progress


class Essentials:

    def __init__(self):
        print("Welcome to the MCU Essentials Installer..by nyzex\n")


    def downloader(self):

        try:
            print("\nDownloading dependencies.rar.......")
            url = f"{os.environ.get("specialLink")}"
            r = requests.get(url, stream = True)
            path = "dependencies.rar"
            with open(path, 'wb') as f:
                total_length = int(r.headers.get('content-length'))
                for chunk in progress.bar(r.iter_content(chunk_size=1024), expected_size=(total_length/1024) + 1):
                    if chunk:
                        f.write(chunk)
                        f.flush()
        except Exception as e:
            print(e)


    def extractor(self):

        try:
            for i in patoolib.list_archive("dependencies.rar"):
                print(i)
        except Exception as e:
            pass

        try:
            print("\n\nExtracting Downloaded Files....THIS MAY TAKE A FEW MINS :P")
            patoolib.extract_archive("dependencies.rar", outdir="{}".format(os.getcwd()))
        except Exception as e:
            print("\nError: Required an Extractor like Winrar installed, or if not extract the files in the same path and re-run this file.")


    def get_essential(self):
        try:
            if not os.path.exists("dependencies.rar"):

                self.downloader()

            if os.path.exists("dependencies.rar"):

                self.extractor()

                arduinoData = "ArduinoData"
                arduinoFolder = "Arduino"
                arduino15 = "Arduino15"
                #current_user = getpass.getuser()
                sourceData= f"{os.getcwd()}\\{arduinoData}"
                sourceHardware= f"{os.getcwd()}\\{arduinoFolder}"
                home = os.path.expanduser('~')

                if os.path.exists("ArduinoData") and os.path.exists("Arduino"):
                    if platform.system() == "Windows" and platform.release() == "10":

                        dest = os.path.join(home,'Documents')
                        print("Windows 10 Detected")

                    if platform.system() == "Windows" and platform.release() == "7":

                        dest = os.path.join(home,'My Documents')
                        print("Windows 7 Detected")

                    if platform.system() == "Windows" and platform.release() == "8" or platform.release() == "8.1":

                        dest = os.path.join(home,'Documents')
                        print("Windows 8 Detected")


                    #dest = os.path.join(home,'Documents')
                    dest_hidden = os.path.join(home,'AppData\\Local')
                    hidden_data = dest_hidden
                    x = dest
                    y = dest
                    x = x+f"\\{arduinoData}\\"
                    y = y+f"\\{arduinoFolder}\\"
                    hidden_data = hidden_data+f"\\{arduino15}\\"

                    try:
                        if not os.path.exists(x):
                            os.mkdir(x)
                        print(x)
                        print("\nCopying Libraries.......")
                        distutils.dir_util.copy_tree(sourceData, x)
                    except Exception as e:
                        print(e)

                    try:
                        if not os.path.exists(y):
                            os.mkdir(y)
                        print(y)
                        print("\nCopying Hardware Files.....")
                        distutils.dir_util.copy_tree(sourceHardware, y)
                    except Exception as e:
                        print(e)

                    try:
                        if not os.path.exists(hidden_data):
                            os.mkdir(hidden_data)
                        print(hidden_data)
                        print("\nCopying Essential Files.....")
                        distutils.dir_util.copy_tree(sourceData, hidden_data)
                    except Exception as e:
                        print(e)

                    print("\n\nTask Completed Successfully!! Kappa!")

                else:
                    print("\nError: Missing 'Arduino' Folder from rar, download and extract again?yes or no")
                    choice = input(">").lower()
                    if(choice == "y" or choice == yes):
                        self.get_essential()
                    else:
                        quit()
        except Exception as e:
            print(e)


if __name__ == '__main__':
    Essentials().get_essential()
