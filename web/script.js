// =====================================================
// STUDENT MANAGEMENT SYSTEM
// =====================================================


// =====================================================
// GET STUDENTS FROM LOCAL STORAGE
// =====================================================

function getStudents() {
    return JSON.parse(localStorage.getItem("students")) || [];
}


// =====================================================
// SAVE STUDENTS
// =====================================================

function saveStudents(students) {
    localStorage.setItem("students", JSON.stringify(students));
}


// =====================================================
// ADMIN LOGIN
// =====================================================

const adminLoginForm = document.getElementById("adminLoginForm");

if (adminLoginForm) {

    adminLoginForm.addEventListener("submit", function (event) {

        event.preventDefault();

        const username =
            document.getElementById("adminUsername").value.trim();

        const password =
            document.getElementById("adminPassword").value;

        if (username === "admin" && password === "1234") {

            document.getElementById("loginMessage").textContent =
                "Admin Login Successful!";

            window.location.href = "admin.html";

        } else {

            document.getElementById("loginMessage").textContent =
                "Invalid username or password!";
        }

    });
}


// =====================================================
// COURSE - OTHER
// =====================================================

const courseSelect = document.getElementById("courseSelect");
const otherCourse = document.getElementById("otherCourse");

if (courseSelect && otherCourse) {

    courseSelect.addEventListener("change", function () {

        if (this.value === "Other") {

            otherCourse.style.display = "block";
            otherCourse.required = true;

        } else {

            otherCourse.style.display = "none";
            otherCourse.required = false;
            otherCourse.value = "";
        }

    });
}


// =====================================================
// BRANCH - OTHER
// =====================================================

const branchSelect = document.getElementById("branchSelect");
const otherBranch = document.getElementById("otherBranch");

if (branchSelect && otherBranch) {

    branchSelect.addEventListener("change", function () {

        if (this.value === "Other") {

            otherBranch.style.display = "block";
            otherBranch.required = true;

        } else {

            otherBranch.style.display = "none";
            otherBranch.required = false;
            otherBranch.value = "";
        }

    });
}


// =====================================================
// SEMESTER - OTHER
// =====================================================

const semesterSelect = document.getElementById("semesterSelect");
const otherSemester = document.getElementById("otherSemester");

if (semesterSelect && otherSemester) {

    semesterSelect.addEventListener("change", function () {

        if (this.value === "Other") {

            otherSemester.style.display = "block";
            otherSemester.required = true;

        } else {

            otherSemester.style.display = "none";
            otherSemester.required = false;
            otherSemester.value = "";
        }

    });
}


// =====================================================
// ADD STUDENT
// =====================================================

const studentForm = document.getElementById("studentForm");

if (studentForm) {

    studentForm.addEventListener("submit", function (event) {

        event.preventDefault();


        // NAME
        const name =
            document.getElementById("studentName").value.trim();

        if (name === "") {

            alert("Please enter student name.");
            return;
        }


        // COURSE
        let course =
            document.getElementById("courseSelect").value;

        if (course === "") {

            alert("Please select course.");
            return;
        }

        if (course === "Other") {

            course =
                document.getElementById("otherCourse").value.trim();

            if (course === "") {

                alert("Please enter your course.");
                return;
            }
        }


        // BRANCH
        let branch =
            document.getElementById("branchSelect").value;

        if (branch === "") {

            alert("Please select branch.");
            return;
        }

        if (branch === "Other") {

            branch =
                document.getElementById("otherBranch").value.trim();

            if (branch === "") {

                alert("Please enter your branch.");
                return;
            }
        }


        // SEMESTER
        let semester =
            document.getElementById("semesterSelect").value;

        if (semester === "") {

            alert("Please select semester.");
            return;
        }

        if (semester === "Other") {

            semester =
                document.getElementById("otherSemester").value.trim();

            if (semester === "") {

                alert("Please enter semester.");
                return;
            }
        }


        // ROLL NUMBER
        const roll =
            Number(document.getElementById("roll").value);

        if (!Number.isInteger(roll) || roll <= 0) {

            alert("Invalid roll number.");
            return;
        }


        // EMAIL
        const email =
            document.getElementById("email").value.trim();

        if (email === "") {

            alert("Please enter email.");
            return;
        }


        // AGE
        const age =
            Number(document.getElementById("age").value);

        if (age <= 0) {

            alert("Invalid age.");
            return;
        }


        // ATTENDANCE
        const attendance =
            Number(document.getElementById("attendance").value);

        if (attendance < 0 || attendance > 100) {

            alert("Attendance must be between 0 and 100.");
            return;
        }


        // MARKS
        const marks =
            Number(document.getElementById("marks").value);

        if (marks < 0 || marks > 100) {

            alert("Marks must be between 0 and 100.");
            return;
        }


        // FEES
        const totalFee =
            Number(document.getElementById("totalFee").value);

        const paidFee =
            Number(document.getElementById("paidFee").value);

        if (totalFee < 0 || paidFee < 0) {

            alert("Fee cannot be negative.");
            return;
        }

        if (paidFee > totalFee) {

            alert("Paid fee cannot be greater than total fee.");
            return;
        }


        // GET STUDENTS
        let students = getStudents();


        // DUPLICATE ROLL
        const duplicate =
            students.some(function (student) {

                return Number(student.roll) === roll;

            });


        if (duplicate) {

            alert("This Roll Number already exists!");
            return;
        }


        // CREATE STUDENT
        const student = {

            name: name,
            course: course,
            branch: branch,
            semester: semester,
            roll: roll,
            email: email,
            age: age,
            attendance: attendance,
            marks: marks,
            totalFee: totalFee,
            paidFee: paidFee

        };


        // ADD STUDENT
        students.push(student);


        // SAVE
        saveStudents(students);


        // SUCCESS MESSAGE
        const formMessage =
            document.getElementById("formMessage");

        if (formMessage) {

            formMessage.textContent =
                "Student added successfully!";
        }


        // RESET FORM
        studentForm.reset();


        if (otherCourse) {

            otherCourse.style.display = "none";
            otherCourse.required = false;
        }

        if (otherBranch) {

            otherBranch.style.display = "none";
            otherBranch.required = false;
        }

        if (otherSemester) {

            otherSemester.style.display = "none";
            otherSemester.required = false;
        }


        displayStudents();
        updateStatistics();

    });

}


// =====================================================
// GET GRADE
// =====================================================

function getGrade(marks) {

    marks = Number(marks);

    if (marks >= 90)
        return "A";

    if (marks >= 80)
        return "B";

    if (marks >= 70)
        return "C";

    if (marks >= 60)
        return "D";

    if (marks >= 50)
        return "E";

    return "F";
}


// =====================================================
// DISPLAY STUDENTS
// =====================================================

function displayStudents() {

    const studentList =
        document.getElementById("studentList");

    if (!studentList) {
        return;
    }


    const students = getStudents();


    if (students.length === 0) {

        studentList.innerHTML =
            "<p>No student records available.</p>";

        return;
    }


    studentList.innerHTML = "";


    students.forEach(function (student, index) {

        const marks =
            Number(student.marks) || 0;

        const totalFee =
            Number(student.totalFee) || 0;

        const paidFee =
            Number(student.paidFee) || 0;

        const dueFee =
            totalFee - paidFee;

        const grade =
            getGrade(marks);

        const result =
            marks >= 50 ? "PASS" : "FAIL";

        const feeStatus =
            paidFee >= totalFee ? "PAID" : "DUE";


        const card =
            document.createElement("div");

        card.className = "student-card";


        card.innerHTML = `

            <h3>${student.name}</h3>

            <p>
                <strong>Roll Number:</strong>
                ${student.roll}
            </p>

            <p>
                <strong>Course:</strong>
                ${student.course}
            </p>

            <p>
                <strong>Branch:</strong>
                ${student.branch || "Not Available"}
            </p>

            <p>
                <strong>Semester:</strong>
                ${student.semester}
            </p>

            <p>
                <strong>Email:</strong>
                ${student.email}
            </p>

            <p>
                <strong>Age:</strong>
                ${student.age}
            </p>

            <p>
                <strong>Attendance:</strong>
                ${student.attendance}%
            </p>

            <p>
                <strong>Marks:</strong>
                ${marks}
            </p>

            <p>
                <strong>Grade:</strong>
                ${grade}
            </p>

            <p>
                <strong>Result:</strong>
                ${result}
            </p>

            <p>
                <strong>Total Fee:</strong>
                ₹${totalFee.toFixed(2)}
            </p>

            <p>
                <strong>Paid Fee:</strong>
                ₹${paidFee.toFixed(2)}
            </p>

            <p>
                <strong>Due Fee:</strong>
                ₹${dueFee.toFixed(2)}
            </p>

            <p>
                <strong>Fee Status:</strong>
                ${feeStatus}
            </p>

            <button
                type="button"
                class="update-btn"
                data-index="${index}"
            >
                Update
            </button>

            <button
                type="button"
                class="delete-btn"
                data-index="${index}"
            >
                Delete
            </button>

            <hr>

        `;


        studentList.appendChild(card);

    });

}


// =====================================================
// UPDATE + DELETE BUTTON
// =====================================================

const studentList =
    document.getElementById("studentList");


if (studentList) {

    studentList.addEventListener("click", function (event) {

        // UPDATE
        if (
            event.target.classList.contains("update-btn")
        ) {

            const index =
                Number(event.target.dataset.index);

            editStudent(index);
        }


        // DELETE
        if (
            event.target.classList.contains("delete-btn")
        ) {

            const index =
                Number(event.target.dataset.index);

            deleteStudent(index);
        }

    });

}


// =====================================================
// UPDATE STUDENT
// =====================================================

function editStudent(index) {

    const students = getStudents();


    // CHECK STUDENT
    if (
        index < 0 ||
        index >= students.length
    ) {

        alert("Student not found!");
        return;
    }


    const oldStudent =
        students[index];


    // =================================================
    // NAME
    // =================================================

    const name =
        prompt(
            "Enter Student Name:",
            oldStudent.name
        );

    if (name === null) {
        return;
    }

    if (name.trim() === "") {

        alert("Name cannot be empty!");
        return;
    }


    // =================================================
    // COURSE
    // =================================================

    const course =
        prompt(
            "Enter Course:",
            oldStudent.course
        );

    if (course === null) {
        return;
    }

    if (course.trim() === "") {

        alert("Course cannot be empty!");
        return;
    }


    // =================================================
    // BRANCH
    // =================================================

    const branch =
        prompt(
            "Enter Branch:",
            oldStudent.branch || ""
        );

    if (branch === null) {
        return;
    }

    if (branch.trim() === "") {

        alert("Branch cannot be empty!");
        return;
    }


    // =================================================
    // SEMESTER
    // =================================================

    const semester =
        prompt(
            "Enter Semester (1-8 or Other):",
            oldStudent.semester
        );

    if (semester === null) {
        return;
    }

    if (semester.trim() === "") {

        alert("Semester cannot be empty!");
        return;
    }


    // =================================================
    // ROLL NUMBER
    // =================================================

    const rollInput =
        prompt(
            "Enter Roll Number:",
            oldStudent.roll
        );

    if (rollInput === null) {
        return;
    }


    const roll =
        Number(rollInput);


    if (
        !Number.isInteger(roll) ||
        roll <= 0
    ) {

        alert("Invalid Roll Number!");
        return;
    }


    // =================================================
    // DUPLICATE ROLL
    // =================================================

    const duplicate =
        students.some(function (student, i) {

            return (
                i !== index &&
                Number(student.roll) === roll
            );

        });


    if (duplicate) {

        alert(
            "This Roll Number already exists!"
        );

        return;
    }


    // =================================================
    // EMAIL
    // =================================================

    const email =
        prompt(
            "Enter Email:",
            oldStudent.email
        );

    if (email === null) {
        return;
    }

    if (email.trim() === "") {

        alert("Email cannot be empty!");
        return;
    }


    // =================================================
    // AGE
    // =================================================

    const ageInput =
        prompt(
            "Enter Age:",
            oldStudent.age
        );

    if (ageInput === null) {
        return;
    }


    const age =
        Number(ageInput);


    if (
        !Number.isInteger(age) ||
        age <= 0
    ) {

        alert("Invalid Age!");
        return;
    }


    // =================================================
    // ATTENDANCE
    // =================================================

    const attendanceInput =
        prompt(
            "Enter Attendance (0-100):",
            oldStudent.attendance
        );

    if (attendanceInput === null) {
        return;
    }


    const attendance =
        Number(attendanceInput);


    if (
        attendance < 0 ||
        attendance > 100
    ) {

        alert(
            "Attendance must be between 0 and 100!"
        );

        return;
    }


    // =================================================
    // MARKS
    // =================================================

    const marksInput =
        prompt(
            "Enter Marks (0-100):",
            oldStudent.marks
        );

    if (marksInput === null) {
        return;
    }


    const marks =
        Number(marksInput);


    if (
        marks < 0 ||
        marks > 100
    ) {

        alert(
            "Marks must be between 0 and 100!"
        );

        return;
    }


    // =================================================
    // TOTAL FEE
    // =================================================

    const totalFeeInput =
        prompt(
            "Enter Total Fee:",
            oldStudent.totalFee
        );

    if (totalFeeInput === null) {
        return;
    }


    const totalFee =
        Number(totalFeeInput);


    if (
        isNaN(totalFee) ||
        totalFee < 0
    ) {

        alert("Invalid Total Fee!");
        return;
    }


    // =================================================
    // PAID FEE
    // =================================================

    const paidFeeInput =
        prompt(
            "Enter Paid Fee:",
            oldStudent.paidFee
        );

    if (paidFeeInput === null) {
        return;
    }


    const paidFee =
        Number(paidFeeInput);


    if (
        isNaN(paidFee) ||
        paidFee < 0
    ) {

        alert("Invalid Paid Fee!");
        return;
    }


    if (paidFee > totalFee) {

        alert(
            "Paid Fee cannot be greater than Total Fee!"
        );

        return;
    }


    // =================================================
    // UPDATE STUDENT
    // =================================================

    students[index] = {

        name: name.trim(),

        course: course.trim(),

        branch: branch.trim(),

        semester: semester.trim(),

        roll: roll,

        email: email.trim(),

        age: age,

        attendance: attendance,

        marks: marks,

        totalFee: totalFee,

        paidFee: paidFee

    };


    // =================================================
    // SAVE UPDATED DATA
    // =================================================

    saveStudents(students);


    // =================================================
    // REFRESH PAGE DATA
    // =================================================

    displayStudents();

    updateStatistics();


    alert(
        "Student updated successfully!"
    );
}


// =====================================================
// DELETE STUDENT
// =====================================================

function deleteStudent(index) {

    const students = getStudents();


    if (
        index < 0 ||
        index >= students.length
    ) {

        alert("Student not found!");
        return;
    }


    const confirmDelete =
        confirm(
            "Are you sure you want to delete " +
            students[index].name +
            "?"
        );


    if (!confirmDelete) {
        return;
    }


    students.splice(index, 1);


    saveStudents(students);


    displayStudents();

    updateStatistics();


    alert(
        "Student deleted successfully!"
    );
}


// =====================================================
// SORT STUDENTS
// =====================================================

function sortStudents() {

    const students = getStudents();


    if (students.length === 0) {

        alert("No students available!");
        return;
    }


    students.sort(function (a, b) {

        return Number(b.marks) -
               Number(a.marks);

    });


    saveStudents(students);


    displayStudents();

    updateStatistics();


    alert(
        "Students sorted by marks successfully!"
    );
}


// =====================================================
// STATISTICS
// =====================================================

function updateStatistics() {

    const students =
        getStudents();


    const total =
        students.length;


    let totalMarks = 0;

    let highestMarks = 0;

    let lowestMarks = 0;

    let passed = 0;

    let failed = 0;

    let totalFee = 0;

    let paidFee = 0;

    let lowAttendance = 0;


    if (total > 0) {

        highestMarks =
            Number(students[0].marks);

        lowestMarks =
            Number(students[0].marks);


        students.forEach(function (student) {

            const marks =
                Number(student.marks);

            const attendance =
                Number(student.attendance);

            const studentTotalFee =
                Number(student.totalFee);

            const studentPaidFee =
                Number(student.paidFee);


            totalMarks += marks;

            totalFee += studentTotalFee;

            paidFee += studentPaidFee;


            if (marks > highestMarks) {

                highestMarks = marks;
            }


            if (marks < lowestMarks) {

                lowestMarks = marks;
            }


            if (marks >= 50) {

                passed++;

            } else {

                failed++;
            }


            if (attendance < 75) {

                lowAttendance++;
            }

        });

    }


    const averageMarks =
        total > 0
            ? totalMarks / total
            : 0;


    const pendingFee =
        totalFee - paidFee;


    // DASHBOARD

    const totalStudents =
        document.getElementById("totalStudents");

    if (totalStudents) {

        totalStudents.textContent =
            total;
    }


    const passedStudents =
        document.getElementById("passedStudents");

    if (passedStudents) {

        passedStudents.textContent =
            passed;
    }


    const failedStudents =
        document.getElementById("failedStudents");

    if (failedStudents) {

        failedStudents.textContent =
            failed;
    }


    const pendingFees =
        document.getElementById("pendingFees");

    if (pendingFees) {

        pendingFees.textContent =
            "₹" +
            pendingFee.toFixed(2);
    }


    // STATISTICS

    const statTotal =
        document.getElementById("statTotal");

    if (statTotal) {

        statTotal.textContent =
            total;
    }


    const averageMarksElement =
        document.getElementById("averageMarks");

    if (averageMarksElement) {

        averageMarksElement.textContent =
            averageMarks.toFixed(2);
    }


    const highestMarksElement =
        document.getElementById("highestMarks");

    if (highestMarksElement) {

        highestMarksElement.textContent =
            highestMarks.toFixed(2);
    }


    const lowestMarksElement =
        document.getElementById("lowestMarks");

    if (lowestMarksElement) {

        lowestMarksElement.textContent =
            lowestMarks.toFixed(2);
    }


    const statPassed =
        document.getElementById("statPassed");

    if (statPassed) {

        statPassed.textContent =
            passed;
    }


    const statFailed =
        document.getElementById("statFailed");

    if (statFailed) {

        statFailed.textContent =
            failed;
    }


    const statTotalFee =
        document.getElementById("statTotalFee");

    if (statTotalFee) {

        statTotalFee.textContent =
            totalFee.toFixed(2);
    }


    const statPaidFee =
        document.getElementById("statPaidFee");

    if (statPaidFee) {

        statPaidFee.textContent =
            paidFee.toFixed(2);
    }


    const statPendingFee =
        document.getElementById("statPendingFee");

    if (statPendingFee) {

        statPendingFee.textContent =
            pendingFee.toFixed(2);
    }


    const lowAttendanceElement =
        document.getElementById("lowAttendance");

    if (lowAttendanceElement) {

        lowAttendanceElement.textContent =
            lowAttendance;
    }

}


// =====================================================
// SEARCH STUDENT
// =====================================================

const searchForm =
    document.getElementById("searchForm");


if (searchForm) {

    searchForm.addEventListener(
        "submit",
        function (event) {

            event.preventDefault();


            const searchValue =
                document.getElementById(
                    "searchInput"
                )
                .value
                .trim()
                .toLowerCase();


            const searchResult =
                document.getElementById(
                    "searchResult"
                );


            const students =
                getStudents();


            const student =
                students.find(function (item) {

                    return (

                        String(item.roll) ===
                        searchValue

                        ||

                        String(item.name)
                            .toLowerCase() ===
                        searchValue

                    );

                });


            if (!student) {

                searchResult.innerHTML =
                    "<p>Student not found!</p>";

                return;
            }


            const marks =
                Number(student.marks) || 0;

            const totalFee =
                Number(student.totalFee) || 0;

            const paidFee =
                Number(student.paidFee) || 0;

            const dueFee =
                totalFee - paidFee;


            const grade =
                getGrade(marks);


            const result =
                marks >= 50
                    ? "PASS"
                    : "FAIL";


            const feeStatus =
                paidFee >= totalFee
                    ? "PAID"
                    : "DUE";


            searchResult.innerHTML = `

                <div class="student-card">

                    <h3>${student.name}</h3>

                    <p>
                        <strong>Roll Number:</strong>
                        ${student.roll}
                    </p>

                    <p>
                        <strong>Course:</strong>
                        ${student.course}
                    </p>

                    <p>
                        <strong>Branch:</strong>
                        ${student.branch || "Not Available"}
                    </p>

                    <p>
                        <strong>Semester:</strong>
                        ${student.semester}
                    </p>

                    <p>
                        <strong>Email:</strong>
                        ${student.email}
                    </p>

                    <p>
                        <strong>Age:</strong>
                        ${student.age}
                    </p>

                    <p>
                        <strong>Attendance:</strong>
                        ${student.attendance}%
                    </p>

                    <p>
                        <strong>Marks:</strong>
                        ${marks}
                    </p>

                    <p>
                        <strong>Grade:</strong>
                        ${grade}
                    </p>

                    <p>
                        <strong>Result:</strong>
                        ${result}
                    </p>

                    <p>
                        <strong>Total Fee:</strong>
                        ₹${totalFee.toFixed(2)}
                    </p>

                    <p>
                        <strong>Paid Fee:</strong>
                        ₹${paidFee.toFixed(2)}
                    </p>

                    <p>
                        <strong>Due Fee:</strong>
                        ₹${dueFee.toFixed(2)}
                    </p>

                    <p>
                        <strong>Fee Status:</strong>
                        ${feeStatus}
                    </p>

                </div>

            `;


            const profile =
                document.getElementById(
                    "studentProfile"
                );


            if (profile) {

                profile.innerHTML =
                    searchResult.innerHTML;
            }

        }
    );

}


// =====================================================
// SORT BUTTON
// =====================================================

const sortButton =
    document.querySelector(
        'button[onclick="sortStudents()"]'
    );


if (sortButton) {

    sortButton.removeAttribute("onclick");

    sortButton.addEventListener(
        "click",
        sortStudents
    );
}


// =====================================================
// INITIAL LOAD
// =====================================================

displayStudents();

updateStatistics();