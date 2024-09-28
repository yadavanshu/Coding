// src/App.js
import React from "react";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import MobileList from "./components/MobileList";
import MobileDetail from "./components/MobileDetail";

const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<MobileList />} />
        <Route path="/mobile/:slug" element={<MobileDetail />} />
      </Routes>
    </Router>
  );
};

export default App;
