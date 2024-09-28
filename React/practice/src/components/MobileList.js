// src/components/MobileList.js
import React, { useEffect, useState } from "react";
import axios from "axios";
import { Link } from "react-router-dom";

const MobileList = () => {
  const [mobiles, setMobiles] = useState([]);

  useEffect(() => {
    axios
      .get("https://phone-specs-api.azharimm.dev/latest")
      .then((response) => {
        setMobiles(response.data.data.phones);
      })
      .catch((error) => {
        console.error("Error fetching mobile data:", error);
      });
  }, []);

  return (
    <div>
        <h1>Mobile Specifications</h1>
        <ul>
        {mobiles.map((mobile) => (
            <li key={mobile.slug}>
                <Link to={`/mobile/${mobile.slug}`}>{mobile.phone_name}</Link>
            </li>
        ))}
        </ul>
    </div>
    );
};

export default MobileList;
