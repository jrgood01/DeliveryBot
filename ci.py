import os
import sys

if __name__ == "main":
    if len(sys.argv) < 1:
        print("Please select branch")
    else:
        os.system("git clone https://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@github.com/jrgood01/DeliveryBot.git")
        os.system(f'git checkout {sys.argv[1]}')
        os.system('make main')
        os.system('./main')
        