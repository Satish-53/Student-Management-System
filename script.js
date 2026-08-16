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
