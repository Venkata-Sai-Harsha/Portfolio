'use strict';



// element toggle function
const elementToggleFunc = function (elem) { elem.classList.toggle("active"); }



// sidebar variables
const sidebar = document.querySelector("[data-sidebar]");
const sidebarBtn = document.querySelector("[data-sidebar-btn]");

// sidebar toggle functionality for mobile
sidebarBtn.addEventListener("click", function () { elementToggleFunc(sidebar); });



// testimonials variables
const testimonialsItem = document.querySelectorAll("[data-testimonials-item]");
const modalContainer = document.querySelector("[data-modal-container]");
const modalCloseBtn = document.querySelector("[data-modal-close-btn]");
const overlay = document.querySelector("[data-overlay]");

// modal variable
const modalImg = document.querySelector("[data-modal-img]");
const modalTitle = document.querySelector("[data-modal-title]");
const modalText = document.querySelector("[data-modal-text]");

// modal toggle function
const testimonialsModalFunc = function () {
  modalContainer.classList.toggle("active");
  overlay.classList.toggle("active");
}

// add click event to all modal items
for (let i = 0; i < testimonialsItem.length; i++) {

  testimonialsItem[i].addEventListener("click", function () {

    modalImg.src = this.querySelector("[data-testimonials-avatar]").src;
    modalImg.alt = this.querySelector("[data-testimonials-avatar]").alt;
    modalTitle.innerHTML = this.querySelector("[data-testimonials-title]").innerHTML;
    modalText.innerHTML = this.querySelector("[data-testimonials-text]").innerHTML;

    testimonialsModalFunc();

  });

}

// add click event to modal close button
modalCloseBtn.addEventListener("click", testimonialsModalFunc);
overlay.addEventListener("click", testimonialsModalFunc);



// custom select variables
const select = document.querySelector("[data-select]");
const selectItems = document.querySelectorAll("[data-select-item]");
const selectValue = document.querySelector("[data-selecct-value]");
const filterBtn = document.querySelectorAll("[data-filter-btn]");

select.addEventListener("click", function () { elementToggleFunc(this); });

// add event in all select items
for (let i = 0; i < selectItems.length; i++) {
  selectItems[i].addEventListener("click", function () {

    let selectedValue = this.innerText.toLowerCase();
    selectValue.innerText = this.innerText;
    elementToggleFunc(select);
    filterFunc(selectedValue);

  });
}

// filter variables
const filterItems = document.querySelectorAll("[data-filter-item]");

const filterFunc = function (selectedValue) {

  for (let i = 0; i < filterItems.length; i++) {

    if (selectedValue === "all") {
      filterItems[i].classList.add("active");
    } else if (selectedValue === filterItems[i].dataset.category) {
      filterItems[i].classList.add("active");
    } else {
      filterItems[i].classList.remove("active");
    }

  }

}

// add event in all filter button items for large screen
let lastClickedBtn = filterBtn[0];

for (let i = 0; i < filterBtn.length; i++) {

  filterBtn[i].addEventListener("click", function () {

    let selectedValue = this.innerText.toLowerCase();
    selectValue.innerText = this.innerText;
    filterFunc(selectedValue);

    lastClickedBtn.classList.remove("active");
    this.classList.add("active");
    lastClickedBtn = this;

  });

}



// contact form variables
const form = document.querySelector("[data-form]");
const formInputs = document.querySelectorAll("[data-form-input]");
const formBtn = document.querySelector("[data-form-btn]");

// add event to all form input field
for (let i = 0; i < formInputs.length; i++) {
  formInputs[i].addEventListener("input", function () {

    // check form validation
    if (form.checkValidity()) {
      formBtn.removeAttribute("disabled");
    } else {
      formBtn.setAttribute("disabled", "");
    }

  });
}



// page navigation variables
const navigationLinks = document.querySelectorAll("[data-nav-link]");
const pages = document.querySelectorAll("[data-page]");

// add event to all nav link
for (let i = 0; i < navigationLinks.length; i++) {
  navigationLinks[i].addEventListener("click", function () {

    for (let i = 0; i < pages.length; i++) {
      if (this.innerHTML.toLowerCase() === pages[i].dataset.page) {
        pages[i].classList.add("active");
        navigationLinks[i].classList.add("active");
        window.scrollTo(0, 0);
      } else {
        pages[i].classList.remove("active");
        navigationLinks[i].classList.remove("active");
      }
    }

  });
}

function openModal(project) {
  var title = "";
  var desc = "";
  var imgSrc = "";
  var codeLink = "";

  if (project === "phishing") {
    title = "Phishing Website Detection using LLMs";
    desc = "Developed a multimodal phishing detection system utilizing GPT-2, RAG, OCR, and BLIP to classify URLs, screenshots, and HTML code.";
    imgSrc = "./assets/images/project-1.png";
    codeLink = "https://github.com/yourusername/phishing-detection";
  } else if (project === "churn") {
    title = "Employee Churn Prediction";
    desc = "Built an ML model to predict employee churn based on behavioral and performance features, achieving high accuracy.";
    imgSrc = "./assets/images/project-2.jpg";
    codeLink = "https://github.com/yourusername/employee-churn";
  } else if (project === "price-tracker") {
    title = "Price Tracking System";
    desc = "A full-stack application to monitor product prices on Amazon, built with Flask backend and React frontend.";
    imgSrc = "./assets/images/project-3.jpg";
    codeLink = "https://github.com/yourusername/price-tracker";
  } else if (project === "bus-management") {
    title = "Bus Management System";
    desc = "Java-based desktop application with JDBC for managing bus schedules, ticketing, and customer records.";
    imgSrc = "./assets/images/project-4.webp";
    codeLink = "https://github.com/yourusername/bus-management";
  } else if (project === "2048") {
    title = "2048 Game";
    desc = "Developed a fully functional 2048 game using HTML, CSS, and JavaScript, implementing dynamic tile generation.";
    imgSrc = "./assets/images/project-5.jpg";
    codeLink = "https://github.com/yourusername/2048-game";
  } else if (project === "math-game") {
    title = "Math Game";
    desc = "Fun web game to test arithmetic speed and accuracy using HTML, CSS, and JavaScript.";
    imgSrc = "./assets/images/project-6.png";
    codeLink = "https://github.com/yourusername/math-game";
  } else if (project === "photo-gallery") {
    title = "Photo Gallery";
    desc = "Created a responsive Pinterest-style photo gallery usingx HTML, CSS, and JavaScript.";
    imgSrc = "./assets/images/project-7.jpg";
    codeLink = "https://github.com/yourusername/photo-gallery";
  } else if (project === "notes-app") {
    title = "Notes App";
    desc = "Developed a basic notes-taking app for Android with SQLite backend, enabling CRUD operations.";
    imgSrc = "./assets/images/project-8.webp";
    codeLink = "https://github.com/yourusername/notes-app";
  } else if (project === "chat-app") {
    title = "Real-time Chat App";
    desc = "Built a real-time chat application using Python sockets enabling multiple clients to communicate through a server.";
    imgSrc = "./assets/images/project-9.jpg";
    codeLink = "https://github.com/yourusername/chat-app";
  }

  document.getElementById('modalTitle').innerText = title;
  document.getElementById('modalDesc').innerText = desc;
  document.getElementById('modalImage').src = imgSrc;
  document.getElementById('modalLink').href = codeLink;
  document.getElementById('projectModal').style.display = 'flex';
}

function closeModal() {
  document.getElementById('projectModal').style.display = 'none';
}