const mongoose = require("mongoose");

const mongo_url =
    "mongodb+srv://harshramchandani122003:harsh123@cluster0.l5tud.mongodb.net/";

const connectToMongo = async() => {
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



const updatebyName = async() => {
    await connectToMongo();
    try {
        const trainer = await TrainerModel.findOne({ name: "Harsh" });
        if (trainer) {
            trainer.phone_number = '8529373955'
            const updatedTrainer = await TrainerModel.findOneAndUpdate({ name: "Harsh" }, { phone_number: '111112111441' }, { new: true }, );
            console.log('trainer by name', updatedTrainer);
        }
    } catch (err) {
        console.log(err)

    } finally {
        await mongoose.disconnect();
        console.log('connection closed')
    }
}
updatebyName();