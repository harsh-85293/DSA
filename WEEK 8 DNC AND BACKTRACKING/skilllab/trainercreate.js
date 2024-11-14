const mongoose = require("mongoose");

const mongo_url =
  "mongodb+srv://harshramchandani122003:harsh123@cluster0.l5tud.mongodb.net/";

const connectToMongo = async () => {
  mongoose.Promise = global.Promise;

  try {
    await mongoose.connect(mongo_url);
    console.log("Connected to MongoDB");
  } catch (err) {
    console.error("Error connecting to MongoDB", err);
    process.exit(1);
  }
};

const collection_name = "trainer";
const collection_fields = {
  name: String,
  location: String,
  technology: String,
  phone_number: String,
};
const collection_config = {
  timestamps: false,
};

const schema = mongoose.Schema(collection_fields, collection_config);
const TrainerModel = mongoose.model(collection_name, schema);

const createTrainer = async () => {
  await connectToMongo();

  try {
    const trainerModel = new TrainerModel({
      _if: new mongoose.Types.ObjectId(),
      name: "Harsh",
      location: "Mysuru",
      technology: "MERN",
      phone_number: "9813623305",
    });
    96;

    const createdDocument = await trainerModel.save();
    console.log("Trainer created successfully", createdDocument);
  } catch (err) {
    console.error("Error creating trainer", err);
  } finally {
    await mongoose.disconnect();
    console.log("MongoDB connection closed");
  }
};

createTrainer();