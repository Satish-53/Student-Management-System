const admissionForm = document.querySelector("#admissionForm");

if (admissionForm) {
    admissionForm.addEventListener("submit", function (event) {
        event.preventDefault();

        const student = {
            name: document.querySelector("#studentName").value,
            fatherName: document.querySelector("#fatherName").value,
            mobile: document.querySelector("#mobile").value,
            email: document.querySelector("#email").value,
            course: document.querySelector("#course").value,
            branch: document.querySelector("#branch").value,
            admissionDate: document.querySelector("#admissionDate").value
        };

        localStorage.setItem("studentData", JSON.stringify(student));

        alert("Admission submitted successfully!");
    });
}
// Student Login
document.getElementById("studentLoginForm").addEventListener("submit", function(event) {
    event.preventDefault();

    const studentId = document.getElementById("student-id").value.trim();
    const password = document.getElementById("student-password").value;

    if (studentId === "student01" && password === "12345") {
        alert("Student Login Successful!");
        window.location.href = "student.html";
    } else {
        alert("Invalid Student ID or Password!");
    }
});


// Admin Login
document.getElementById("adminLoginForm").addEventListener("submit", function(event) {
    event.preventDefault();

    const username = document.getElementById("adminUsername").value.trim();
    const password = document.getElementById("adminPassword").value;

    if (username === "admin01" && password === "12345") {
        alert("Admin Login Successful!");
        window.location.href = "admin.html";
    } else {
        alert("Invalid Admin Username or Password!");
    }
});
