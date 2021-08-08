from tkinter.filedialog import askopenfilename
from wavelength_to_rgb import wavelength_to_rgb as wtor
from matplotlib import pyplot as plt
import pylab as plb

filename = askopenfilename()

if (filename):
    file = open(filename, mode='r', encoding='UTF-8')
    lines = file.readlines()

    for i in range(22, 1020):
        plt.bar(
            lines[i].split()[0],
            float(lines[i].split()[1]),
            color=wtor(lines[i].split()[0]),
            width=1.0
            )

    plt.xlabel(lines[21].split()[0])
    plb.xticks(rotation=90)
    plt.ylabel(lines[21].split()[1])

    plt.title(filename.split('/')[-1].split('.')[0])

    ax = plt.gca()
    ax.xaxis.set_major_locator(plt.LinearLocator(numticks=21))

    plt.show()
