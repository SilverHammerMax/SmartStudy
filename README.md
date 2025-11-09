# Smart Study
Smart Study is a program designed to pair students for studying and for projects. It uses a custom-made greedy algorithm and the Gale-Shapely algorithm to match up these students.

## Usage
To use this program, just run it from the command-line:
```
$ ./SmartStudy
```

### Adding a Student
To add a student to this program, use the first option in the menu. This will prompt you for:
1. The student's name
2. The student's school ID number
3. The student's major
4. A space-separated list of which periods the student is available during

The program will then add a student with the given information to it's list of students.

### Generating Students
The program allows you to generate an arbitrary number of students. While this is not practically useful, it allows for auditing the program without putting in the effort of adding all the students.
To generate the students, use the second option in the menu. The program will prompt for how many students should be generated and then replace the list of students with this list.

### Importing/Exporting Students
Because it is tedious to add students one at a time using the first option, the program allows for importing and exporting all of the students in JSON format.
To import students, put all of the student information in a JSON file called students.json in the directory the program is being run from and then choose the third option. This will overwrite the students already added.

To export the students, choose the fourth option. The student information will be in a file called students.json at the directory the program is being run from. This will overwrite any students.json file that exists in that location.

### Creating the Pairs
To create the pairs, choose the fifth option. This will create two JSON files: greedyPairs.json and galeShapely.json. These files will contain pairs of student ID's for the pairs created.

### JSON Format
The students.json file will contain an array of JSON objects. Every element in the array will look like this:
```
{
        "availability": [
            true,
            false,
            false,
            false,
            false,
            true,
            false,
            false,
            false,
            true,
            true
        ],
        "id": 0,
        "major": "Haas",
        "name": "Dakota Haas"
    }
```
