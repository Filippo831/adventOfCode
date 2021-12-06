import bitarray

def read_file():
    file = open("./input_test.txt")
    lines = file.readlines()
    return lines

def part1():
    ba = bitarray.bitarray()
    lines = read_file()
    gamma_rate = "" 
    epsilon_rate = ""
    for index in range(len(lines[0])):
        ones = 0
        for line in lines:
            if line[index]:
                ones+=1
        if ones > len(lines) / 2:
            gamma_rate += "1"
        else:
            gamma_rate += "0"
    ba.frombytes(gamma_rate.encode(''))

            

def main():
    part1()

if __name__ == "__main__":
    main()
