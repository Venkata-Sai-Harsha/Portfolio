const users = [
    {
        id: 1,
        name: "Sai Harsha",
        username: "sai_harsha",
        email: "sai_harsha@gmail.com",
        mobile: "9876543210",
        activeStatus: true
    },
    {
        id: 2,
        name: "Vishnu",
        username: "vishnu",
        email: "vishnu@gmail.com",
        mobile: "9898989898",
        activeStatus: false
    },
    {
        id: 3,
        name: "Ravi Kumar",
        username: "ravi_k",
        email: "ravi.kumar@gmail.com",
        mobile: "9123456780",
        activeStatus: true
    },
    {
        id: 4,
        name: "Sneha",
        username: "sneha",
        email: "sneha@gmail.com",
        mobile: "9012345678",
        activeStatus: false
    },
    {
        id: 5,
        name: "Vikram",
        username: "vicky",
        email: "vikram@gmail.com",
        mobile: "9988776655",
        activeStatus: true
    },
    {
        id: 6,
        name: "Anjali Sharma",
        username: "anjali_s",
        email: "anjali.sharma@gmail.com",
        mobile: "9871234567",
        activeStatus: false
    },
    {
        id: 7,
        name: "Rahul Mehta",
        username: "rahul_m",
        email: "rahul.mehta@gmail.com",
        mobile: "9765432180",
        activeStatus: true
    },
    {
        id: 8,
        name: "Deepika Reddy",
        username: "deepika_r",
        email: "deepika.reddy@gmail.com",
        mobile: "9654123780",
        activeStatus: false
    },
    {
        id: 9,
        name: "Arjun Patel",
        username: "arjun_p",
        email: "arjun.patel@gmail.com",
        mobile: "9988771122",
        activeStatus: true
    },
    {
        id: 10,
        name: "Priya Nair",
        username: "priya_n",
        email: "priya.nair@gmail.com",
        mobile: "9123009876",
        activeStatus: true
    },
    {
        id: 11,
        name: "Kiran Rao",
        username: "kiran_rao",
        email: "kiran.rao@gmail.com",
        mobile: "9876549870",
        activeStatus: false
    },
    {
        id: 12,
        name: "Nisha Jain",
        username: "nisha_j",
        email: "nisha.jain@gmail.com",
        mobile: "9001234567",
        activeStatus: true
    }
];

function showUsers(statusType) {
    const filteredUsers = users.filter(user => 
        statusType === 'active' ? user.activeStatus : !user.activeStatus
    );

    let html = `
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Username</th>
                    <th>Email</th>
                    <th>Mobile No</th>
                    <th>Status</th>
                </tr>
            </thead>
            <tbody>
    `;

    filteredUsers.forEach(user => {
        html += `
            <tr>
                <td>${user.id}</td>
                <td>${user.name}</td>
                <td>${user.username}</td>
                <td>${user.email}</td>
                <td>${user.mobile}</td>
                <td>${user.activeStatus ? 'Active' : 'Inactive'}</td>
            </tr>
        `;
    });

    html += `
            </tbody>
        </table>
    `;

    document.getElementById("tableContainer").innerHTML = html;
}


