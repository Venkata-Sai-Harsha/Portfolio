// Get references to DOM elements
var addButton = document.getElementById("add-button");
var clearButton = document.getElementById("clear-completed-button");
var emptyButton = document.getElementById("empty-button");
var saveButton = document.getElementById("save-button");
var toDoEntryBox = document.getElementById("todo-entry-box");
var toDoList = document.getElementById("todo-list");

// Event listeners
addButton.addEventListener("click", addToDoItem);
clearButton.addEventListener("click", clearCompletedToDoItems);
emptyButton.addEventListener("click", emptyList);
saveButton.addEventListener("click", saveList);

// Load list from local storage on page load
loadList();

// Add new to-do item
function addToDoItem() {
    var itemText = toDoEntryBox.value.trim();
    if (itemText !== "") {
        newToDoItem(itemText, false);
        toDoEntryBox.value = ""; // Clear input box after adding
    }
}

// Create a new list item
function newToDoItem(itemText, completed) {
    var toDoItem = document.createElement("li");
    var toDoText = document.createTextNode(itemText);
    toDoItem.appendChild(toDoText);

    if (completed) {
        toDoItem.classList.add("completed");
    }

    toDoItem.addEventListener("dblclick", toggleToDoItemState);
    toDoList.appendChild(toDoItem);
}

// Toggle completion state on double-click
function toggleToDoItemState() {
    this.classList.toggle("completed");
}

// Clear all completed items
function clearCompletedToDoItems() {
    var completedItems = toDoList.getElementsByClassName("completed");
    while (completedItems.length > 0) {
        completedItems.item(0).remove();
    }
}

// Remove all items from list
function emptyList() {
    while (toDoList.firstChild) {
        toDoList.removeChild(toDoList.firstChild);
    }
    // localStorage.removeItem("toDos"); 
}

// Save current to-do list to localStorage
function saveList() {
    var toDos = [];

    for (var i = 0; i < toDoList.children.length; i++) {
        var toDo = toDoList.children[i];
        var toDoInfo = {
            task: toDo.innerText,
            completed: toDo.classList.contains("completed")
        };
        toDos.push(toDoInfo);
    }

    localStorage.setItem("toDos", JSON.stringify(toDos));
}

// Load to-do list from localStorage
function loadList() {
    if (localStorage.getItem("toDos")) {
        var toDos = JSON.parse(localStorage.getItem("toDos"));
        for (var i = 0; i < toDos.length; i++) {
            var toDo = toDos[i];
            newToDoItem(toDo.task, toDo.completed);
        }
    }
}
