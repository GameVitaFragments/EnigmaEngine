import sys, os

class Project:
    def __init__(self) -> None:
        self.args = sys.argv
        self.root = os.getcwd()
        self.path = sys.argv[1]
        self.className = sys.argv[2]

    def createFiles(self):
        dir = os.path.join(self.root, self.path, self.className)
        print(dir)
        os.mkdir(dir)

        cpp = open(dir + f"/{self.className}.cpp", 'w')
        cpp.write(f'#include "{self.className}.hpp"\n')
        cpp.close()

        hpp = open(dir + f"/{self.className}.hpp", 'w')
        hpp.write("#pragma once\n")
        hpp.close()

        meson = open(dir + "/meson.build", 'w')
        meson.write(f"sources += files('{self.className}.cpp')")
        meson.close()
        data = []

        with open("meson.build", 'r') as f:
            data = f.readlines()

        i = 0
        for line in data:
            if "subdir" in line:
                data.insert(i-1, f"\nsubdir('{os.path.join(self.path, self.className)}')")
                break
            i += 1

        with open("meson.build", 'w') as f:
            f.writelines(data)


proj = Project()
proj.createFiles()
