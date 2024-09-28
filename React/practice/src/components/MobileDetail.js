// src/components/MobileDetail.js
import React, { useEffect, useState } from "react";
import axios from "axios";
import { useParams } from "react-router-dom";

const MobileDetail = () => {
  const { slug } = useParams();
  const [mobile, setMobile] = useState(null);

  useEffect(() => {
    axios
      .get(`https://phone-specs-api.azharimm.dev/${slug}`)
      .then((response) => {
        setMobile(response.data.data);
      })
      .catch((error) => {
        console.error("Error fetching mobile details:", error);
      });
  }, [slug]);

  if (!mobile) return <div>Loading...</div>;

  return (
    <div>
      <h1>{mobile.phone_name}</h1>
      <p>Brand: {mobile.brand}</p>
      <p>Release Date: {mobile.release_date}</p>
      <h2>Specifications:</h2>
      <ul>
        {mobile.specifications.map((spec, index) => (
          <li key={index}>
            <strong>{spec.title}:</strong>
            {spec.specs.map((detail, idx) => (
              <p key={idx}>
                {detail.key}: {detail.val.join(", ")}
              </p>
            ))}
          </li>
        ))}
      </ul>
    </div>
  );
};

export default MobileDetail;
