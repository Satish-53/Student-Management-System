document.querySelectorAll("form").forEach(function(form) {
    form.addEventListener("submit", function(event) {
        event.preventDefault();
        alert("Form submitted successfully!");
    });
});
