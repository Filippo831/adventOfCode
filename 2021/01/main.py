file = open("input.txt")

lines = file.readlines()

lines = [int(line) for line in lines]

more:int = 0;


def part1(lines, more):
    for a in range(len(lines)-1):
        if lines[a+1] > lines[a]:
            more +=1
    print(more)

def part2(lines):
    my_more = 0
    for index in range(len(lines)-3):
        a = lines[index] + lines[index+1] + lines[index+2]
        b = lines[index+1] + lines[index+2] + lines[index+3]

        if b > a:
            my_more = my_more+1
        
    print(my_more)

def main():
    part1(lines, more)
    part2(lines)



if __name__ == "__main__":
    main();

