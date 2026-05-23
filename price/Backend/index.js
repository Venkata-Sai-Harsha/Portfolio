const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const { Pool } = require('pg');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

const app = express();
const port = 5001;

// Middleware
app.use(cors());
app.use(bodyParser.json());

// PostgreSQL pool setup
const pool = new Pool({
  user: 'postgres',        // replace with your PostgreSQL user
  host: 'localhost',       // replace with your PostgreSQL host if different
  database: 'price',       // the database we created earlier
  password: 'Sai@15442',   // replace with your PostgreSQL password
  port: 5432,              // replace with your PostgreSQL port if different
});

// Utility function to hash passwords
const hashPassword = (password) => {
  return bcrypt.hashSync(password, 10);
};

// Utility function to compare passwords
const comparePassword = (password, hashedPassword) => {
  return bcrypt.compareSync(password, hashedPassword);
};

// Utility function to create JWT token
const createToken = (user) => {
  return jwt.sign({ id: user.id, username: user.username }, 'your_jwt_secret', {
    expiresIn: '1h',
  });
};

// Routes

// Signup route
app.post('/signup', async (req, res) => {
  const { username, email, password } = req.body;
  const hashedPassword = hashPassword(password);

  try {
    const result = await pool.query(
      'INSERT INTO users (username, email, password) VALUES ($1, $2, $3) RETURNING *',
      [username, email, hashedPassword]
    );
    const newUser = result.rows[0];
    const token = createToken(newUser);
    res.json({ username: newUser.username, token });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Login route
app.post('/login', async (req, res) => {
  const { identifier, password } = req.body;

  try {
    const result = await pool.query(
      'SELECT * FROM users WHERE username = $1 OR email = $2',
      [identifier, identifier]
    );
    const user = result.rows[0];

    if (user && comparePassword(password, user.password)) {
      const token = createToken(user);
      res.json({ username: user.username, token });
    } else {
      res.status(400).json({ error: 'Invalid username/email or password' });
    }
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
