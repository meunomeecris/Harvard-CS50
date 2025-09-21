// Select the menu-item and open in the iFrame
document.addEventListener("DOMContentLoaded", function() {
let menuItems = document.querySelectorAll(".menu-item");
let iframe = document.getElementById("content-page");
// Update the iFrame with the page
menuItems.forEach(item => {
    item.addEventListener("click", function(event) {
        event.preventDefault();
        let href = item.getAttribute("href");
        iframe.setAttribute("src", href);
    });
});
});



//  Bootstrap TOOLTIP
const tooltipTriggerList = document.querySelectorAll('[data-bs-toggle="tooltip"]')
const tooltipList = [...tooltipTriggerList].map(tooltipTriggerEl => new bootstrap.Tooltip(tooltipTriggerEl))
