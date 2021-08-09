print(f"Module1 name={__name__}")

print("This will always be run")

def main():
    print("Module1")

if __name__=='__main__':
    main()

#__name__ stores the name of the file
#if the file is run directly by python __name__ will be main
#else if it is imported it will be set to the name of the file/module