def read_file():
    file = open("./input.txt")
    lines = file.readlines()
    return lines

def part1():
    lines = read_file()
    depth = 0
    lenght = 0
    for line in lines:
        if line.find("forward") >= 0:
            index = line.find(" ")
            lenght += int(line[index::])
        if line.find("up") >= 0:
            index = line.find(" ")
            depth -= int(line[index::])
        if line.find("down") >= 0:
            index = line.find(" ")
            depth += int(line[index::])

    print("forward: ", lenght)
    print("depth: ", depth)
    print("final: ", lenght*depth)


def part2():
    lines = read_file()
    aim = 0
    depth = 0
    lenght = 0
    for line in lines:
        if line.find("forward") >= 0:
            index = line.find(" ")
            lenght += int(line[index::])
            depth = depth + int(line[index::]) * aim
        if line.find("up") >= 0:
            index = line.find(" ")
            aim -= int(line[index::])
        if line.find("down") >= 0:
            index = line.find(" ")
            aim += int(line[index::])

    print("forward: ", lenght)
    print("depth: ", depth)
    print("final: ", lenght*depth)

def main():
    part1()
    part2()

if __name__ == "__main__":
    main()
