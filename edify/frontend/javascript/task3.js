function displayInfo() {
    const firstname = document.getElementById("firstname").value.trim();
    const lastname = document.getElementById("lastname").value.trim();
    const mobile = document.getElementById("mobile").value.trim();
    const email = document.getElementById("email").value.trim();

    const fullName = `${firstname} ${lastname}`;

    const outputDiv = document.getElementById("output");
    outputDiv.style.display = "block";  
    outputDiv.innerHTML = `
        <strong>Full Name:</strong> ${fullName}<br>
        <strong>Mobile No:</strong> ${mobile}<br>
        <strong>Email:</strong> ${email}
    `;
}
